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
        BLettersShop solver = new BLettersShop();
        solver.solve(1, in, out);
        out.close();
    }

    static class BLettersShop {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;
        private int[] count;
        private int[][] cnt;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);
            int n = in.nextInt();
            char[] c = in.nextCharArray(n, 1);
            cnt = new int[n + 1][30];
            for (int i = 1; i <= n; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    cnt[i][j - 'a'] = cnt[i - 1][j - 'a'];
                }
                cnt[i][c[i] - 'a']++;
            }
            int m = in.nextInt();
            while (m-- > 0) {
                String S = in.nextString();
                count = new int[30];
                for (int i = 0; i < S.length(); i++) {
                    count[S.charAt(i) - 'a']++;
                }
                int l = 1, r = n;
                while (l != r) {
                    if (l == r - 1) {
                        if (!ch(l)) l = r;
                        break;
                    }
                    int mid = (l + r) >> 1;
                    if (ch(mid)) r = mid;
                    else l = mid + 1;
                }
                out.println(l);
            }
        }

        private boolean ch(int mid) {
            for (char i = 'a'; i <= 'z'; i++) {
                if (cnt[mid][i - 'a'] < count[i - 'a']) return false;
            }
            return true;
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
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

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public char[] nextCharArray(int length, int stIndex) {
            char[] arr = new char[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextCharacter();
            return arr;
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

        public char nextCharacter() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            return (char) c;
        }

    }
}