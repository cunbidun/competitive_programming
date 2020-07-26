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
        BTanyaAndCandies solver = new BTanyaAndCandies();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTanyaAndCandies {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int[] sumE = new int[n + 1];
            int[] sumO = new int[n + 1];
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += a[i];
                if (i % 2 == 0) {
                    sumO[i] = sumO[i - 1];
                    sumE[i] = sumE[i - 2] + a[i];
                } else {
                    sumE[i] = sumE[i - 1];
                    if (i == 1) sumO[i] = a[i];
                    else sumO[i] = sumO[i - 2] + a[i];
                }
            }

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if ((sum - a[i]) % 2 != 0) continue;
                if (i % 2 == 0) {
                    if (sumO[i - 1] + sumE[n] - sumE[i] == (sum - a[i]) / 2) {
                        ans++;
                    }
                } else {
                    if (sumE[i - 1] + sumO[n] - sumO[i] == (sum - a[i]) / 2) {
                        ans++;
                    }
                }
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
            int[] arr = new int[length + stIndex + 10];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}