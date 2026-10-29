def hexdump(byte_data):
    start = byte_data[1] * 256 + byte_data[0]
    pc = start
    print(start)
    chars = ""
    for x in range(2, len(byte_data)):
        # make it pretty
        if (pc - start) % 8 == 0:
            # chars are built during each iteration, but
            # printed when we reach the end of the line
            print(" %s" % chars)
            print("%04X" % pc, end='')
            chars = ""

        # build the chars = only printable chars
        c = byte_data[x]
        chars += chr(c) if 32 <= c <= 127 else '.'
        print(" %02X" % byte_data[x], end='')
        pc += 1  # no ++ op in python!
    # fix final row
    for i in range(0, 8 - (pc - start) % 8):
        print("   ", end='')
    print(" %s" % chars)


if __name__ == "__main__":
    # main function
    file_name = "data/mult.prg"
    try:
        # with closes file when completed.
        with open(file_name, 'rb') as file:
            file_data = file.read()
    except FileNotFoundError:
        print(f"File not found: {file_name}.")
        exit(1)

    hexdump(file_data)
