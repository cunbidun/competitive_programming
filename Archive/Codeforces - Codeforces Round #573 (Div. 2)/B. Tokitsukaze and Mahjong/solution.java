import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BTokitsukazeAndMahjong solver = new BTokitsukazeAndMahjong();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTokitsukazeAndMahjong {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            String[] a = new String[4];
            a[1] = in.nextString();
            a[2] = in.nextString();
            a[3] = in.nextString();
            Arrays.sort(a, 1, 4);

            int tmp1 = a[1].charAt(0) - '0';
            int tmp2 = a[2].charAt(0) - '0';
            int tmp3 = a[3].charAt(0) - '0';
            if (a[3].equals(a[1]) && a[1].equals(a[2])) {
                out.println(0);
                return;
            }
            if (a[3].equals(a[1]) || a[1].equals(a[2]) || a[3].equals(a[2])) {
                out.println(1);
                return;
            }
            if (a[1].charAt(1) == a[2].charAt(1) && a[2].charAt(1) == a[3].charAt(1)) {
                if (tmp1 + 1 == tmp2 && tmp2 + 1 == tmp3) {
                    out.println(0);
                    return;
                }
                if (tmp1 + 1 == tmp2 || tmp2 + 1 == tmp3 || tmp1 + 2 == tmp2 || tmp2 + 2 == tmp3 || tmp1 + 1 == tmp3 || tmp1 + 2 == tmp3) {
                    out.println(1);
                    return;
                }
                out.println(2);
                return;
            }
            if (a[1].charAt(1) == a[2].charAt(1) || a[2].charAt(1) == a[3].charAt(1) || a[3].charAt(1) == a[1].charAt(1)) {
                if ((tmp1 + 1 == tmp2 || tmp1 + 2 == tmp2) && a[1].charAt(1) == a[2].charAt(1)) {
                    out.println(1);
                    return;
                }
                if ((tmp2 + 1 == tmp3 || tmp2 + 2 == tmp3) && a[2].charAt(1) == a[3].charAt(1)) {
                    out.println(1);
                    return;
                }
                if ((tmp1 + 1 == tmp3 || tmp1 + 2 == tmp3) && a[1].charAt(1) == a[3].charAt(1)) {
                    out.println(1);
                    return;
                }
                out.println(2);
            } else {
                out.println(2);
            }
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(int i) {
            out.println(i);
        }

    }
}