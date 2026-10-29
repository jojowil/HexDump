public class SignExt {

    public static void main(String[] args) {
        byte b = (byte)0xff; // 255 unsigned, but -1 signed.

        // se represents the sign-extended value.
        int se = b;
        // nse prohibits sign extension by masking the higher-order bits.
        int nse = b & 0xff;

        // first, we show the decimal representations
        System.out.println("b is " + b + "\nse is " + se + "\nnse is " + nse);
        // then we show how the hex values enlighten the issue.
        System.out.printf("b is %02X%nse is %02X%nnse is %02X", b, se, nse);
    }
}
