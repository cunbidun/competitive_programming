import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        PrintWriter out = new PrintWriter(outputStream);
        ASuperheroTransformation solver = new ASuperheroTransformation();
        solver.solve(1, in, out);
        out.close();
    }

    static class ASuperheroTransformation {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String t = in.nextString();
            String s = in.nextString();
            if (s.length() != t.length()) {
                out.print("No");
                return;
            }
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == t.charAt(i)) continue;
                if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u') {
                    if (t.charAt(i) != 'a' && t.charAt(i) != 'e' && t.charAt(i) != 'i' && t.charAt(i) != 'o' && t.charAt(i) != 'u') {
                        out.println("No");
                        return;
                    }
                } else {
                    if (t.charAt(i) == 'a' || t.charAt(i) == 'e' || t.charAt(i) == 'i' || t.charAt(i) == 'o' || t.charAt(i) == 'u') {
                        out.println("No");
                        return;
                    }
                }
            }
            out.println("Yes");
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
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
}