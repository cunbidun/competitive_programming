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
        DSashaAndOneMoreName solver = new DSashaAndOneMoreName();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSashaAndOneMoreName {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.nextString();
            int cnt = 0;
            int[] cntt = new int[200];
            for (int i = 0; i < s.length(); i++) {
                if (cntt[s.charAt(i)] == 0) {
                    cnt++;
                }
                cntt[s.charAt(i)]++;
            }

            if (cnt == 1) {
                out.println("Impossible");
                return;
            }
            if (cnt == 2) {
                if (cntt[s.charAt(s.length() / 2)] == 1) {
                    out.println("Impossible");
                    return;
                }
            }
            for (int i = 1; i < s.length(); i++) {
                String newS = s.substring(i) + s.substring(0, i);
                if (ch(newS) && !s.equals(newS)) {
                    out.println(1);
                    return;
                }
            }
            out.println(2);
        }

        private boolean ch(String newS) {
            for (int i = 0; i < newS.length(); i++) {
                if (newS.charAt(i) != newS.charAt(newS.length() - i - 1)) return false;
            }
            return true;
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