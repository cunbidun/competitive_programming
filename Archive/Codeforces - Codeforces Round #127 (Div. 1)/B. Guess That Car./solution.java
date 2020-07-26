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
        BGuessThatCar solver = new BGuessThatCar();
        solver.solve(1, in, out);
        out.close();
    }

    static class BGuessThatCar {
        private static final long INFLL = (long) 2e18 + 7;
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            long[][] a = new long[4 * n + 1][4 * m + 1];
            long[] sumRow = new long[4 * n + 1];
            long[] sumCol = new long[4 * m + 1];

            for (int i = 1; i <= 4 * n; i++) {
                for (int j = 1; j <= 4 * m; j++) {
                    if (i % 4 == 2 && j % 4 == 2) a[i][j] = in.nextInt();
                }
            }
//        for (int i =0; i <= 4 * n; i++) {
//            for (int j = 0; j <= 4 * m; j++) {
//                out.print(a[i][j] + " ");
//            }
//            out.println();
//        }
            for (int i = 0; i <= 4 * n; i++) {
                for (int j = 0; j <= 4 * m; j++) {
                    sumCol[j] += a[i][j];
                    sumRow[i] += a[i][j];
                }
            }
            // find min sum(sumRow[xi] * (x - xi)) x min
            int resX = -1;
            long curMinX = INFLL;
            for (int x = 0; x <= 4 * n; x++)
                if (x % 4 == 0) {
                    long curSum = 0;
                    for (int xi = 0; xi <= 4 * n; xi++) {
                        curSum += sumRow[xi] * (x - xi) * (x - xi);
                    }
                    if (curSum < curMinX) {
                        curMinX = curSum;
                        resX = x;
                    }
                }

            // find min sum(sumCol[yi] * (y - yi)) y min
            int resY = -1;
            long curMinY = INFLL;
            for (int y = 0; y <= 4 * m; y++)
                if (y % 4 == 0) {
                    long curSum = 0;
                    for (int yi = 0; yi <= 4 * m; yi++) {
                        curSum += sumCol[yi] * (y - yi) * (y - yi);
                    }
                    if (curSum < curMinY) {
                        curMinY = curSum;
                        resY = y;
                    }
                }
            out.println(curMinX + curMinY);
            out.println(resX / 4 + " " + resY / 4);
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}