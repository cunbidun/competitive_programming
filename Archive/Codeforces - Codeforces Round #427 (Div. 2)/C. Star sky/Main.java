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
        LStarSky solver = new LStarSky();
        solver.solve(1, in, out);
        out.close();
    }

    static class LStarSky {
        private int[][][] s = new int[110][110][12];
        private int[][][] a = new int[110][110][12];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int c = in.nextInt();
            for (int i = 1; i <= n; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int ss = in.nextInt();
                a[x][y][ss]++;
            }
            for (int l = 0; l <= c; l++) {
                for (int i = 1; i <= 100; i++) {
                    for (int j = 1; j <= 100; j++) {
                        s[i][j][l] = s[i - 1][j][l] + s[i][j - 1][l] - s[i - 1][j - 1][l] + a[i][j][l];
                    }
                }
            }
            for (int i = 1; i <= m; i++) {
                int t = in.nextInt();
                int x1 = in.nextInt();
                int y1 = in.nextInt();
                int x2 = in.nextInt();
                int y2 = in.nextInt();
                int ans = 0;
                for (int j = 0; j <= c; j++) {
                    int b = (t + j) % (c + 1);
                    ans += b * (s[x2][y2][j] - s[x1 - 1][y2][j] - s[x2][y1 - 1][j] + s[x1 - 1][y1 - 1][j]);
                }
                out.println(ans);
            }
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

        public static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}