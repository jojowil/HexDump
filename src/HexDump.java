import java.io.FileInputStream;
import java.io.IOException;

public class HexDump {

    public static void hexDump(byte[] bytes) {
        // we and with 0xff to mask off the bits when sign-extended.
        int start = (bytes[1] & 0xff) * 256 + (bytes[0] & 0xff);
        System.out.println(start);
        int pc = start;
        StringBuilder chars = new StringBuilder();

        for (int x = 2; x < bytes.length; x++) {
            // make it pretty
            if ( (pc - start) % 8 == 0 ) {
                // chars are built during each iteration, but
                // printed when we reach the end of the line.
                System.out.printf(" %s", chars);
                System.out.printf("%n%04X:", pc);
                chars.setLength(0);
            }
            // build the chars - only printable chars
            char c = (char)(bytes[x] & 0xff);
            if ( c >= 32 && c <= 127 )
                chars.append(c);
            else
                chars.append('.');
            // the next line uses a ternary operator to achieve the above.
            //chars.append(( c >= 32 && c <= 127 ) ? c : '.')
            System.out.printf(" %02X", bytes[x]);
            pc++;
        }

        // fix final row
        int last = (pc - start) % 8;
        for (int x = 0; x < 8-last; x++)
            System.out.print("   ");
        System.out.printf(" %s", chars);
    }

    public static void main(String[] args) throws IOException {
        FileInputStream in = new FileInputStream("data/mult.prg");

        byte[] file = in.readAllBytes();

        in.close();
        hexDump(file);
    }
}
