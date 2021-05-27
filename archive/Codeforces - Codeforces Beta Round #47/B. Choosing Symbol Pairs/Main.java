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
        BChoosingSymbolPairs solver = new BChoosingSymbolPairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class BChoosingSymbolPairs {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String S = in.nextString();
            int[] cnt = new int[150];
            for (int i = 0; i < S.length(); i++) {
                cnt[S.charAt(i) - '0' + 1]++;
            }
            long ans = 0;
            for (int i = 1; i <= 100; i++) ans += (long) cnt[i] * cnt[i];
            out.println(ans);
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