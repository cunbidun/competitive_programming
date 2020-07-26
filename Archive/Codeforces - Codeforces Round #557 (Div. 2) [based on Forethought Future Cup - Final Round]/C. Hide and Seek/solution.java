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
        CHideAndSeek solver = new CHideAndSeek();
        solver.solve(1, in, out);
        out.close();
    }

    static class CHideAndSeek {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int k = in.nextInt();
            if (n == 1) {
                out.println(0);
                return;
            }
            int[] a = in.nextIntArray(k, 1);
            int[] lastPos = new int[100010];
            int[] firstPos = new int[100010];
            for (int i = 1; i <= 100001; i++) {
                firstPos[i] = -1;
            }
            int ans = 0;
            for (int i = 1; i <= k; i++) {
                lastPos[a[i]] = i;
                if (firstPos[a[i]] == -1) firstPos[a[i]] = i;
            }
            for (int i = 2; i <= n - 1; i++) {
                if (firstPos[i] == -1) {
                    ans += 3;
//                out.println((i) + " " + (i));
                    continue;
                }
                if (firstPos[i + 1] == -1) {
                    ans++;
//                out.println((i) + " " + (i + 1));
                } else {
                    if (lastPos[i + 1] < firstPos[i]) {
                        ans++;
//                    out.println((i) + " " + (i + 1));
                    }
                }

                if (firstPos[i - 1] == -1) {
                    ans++;
//                out.println((i) + " " + (i - 1));
                } else {
                    if (lastPos[i - 1] < firstPos[i]) {
//                    out.println((i) + " " + (i - 1));
                        ans++;
                    }
                }
            }
            if (firstPos[1] == -1) ans += 2;
            else if (firstPos[2] == -1) {
                ans++;
            } else {
                if (lastPos[2] < firstPos[1]) {
                    ans++;
                }
            }
            if (firstPos[n] == -1) ans += 2;
            else if (firstPos[n - 1] == -1) {
                ans++;
            } else {
                if (lastPos[n - 1] < firstPos[n]) ans++;
            }
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}