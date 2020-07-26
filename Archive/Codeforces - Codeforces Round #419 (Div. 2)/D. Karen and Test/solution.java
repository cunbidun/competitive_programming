import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        DKarenAndTest solver = new DKarenAndTest();
        solver.solve(1, in, out);
        out.close();
    }

    static class DKarenAndTest {
        private static final int MOD = (int) 1e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private int[] fac = new int[200010];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            fac[0] = 1;
            for (int i = 1; i <= 200000; i++) {
                fac[i] = Op.mulMod(fac[i - 1], i, MOD);
            }
            int n = in.nextInt();

            long[] a = in.nextLongArray(n, 1);
            if (n == 1) {
                out.println(a[1]);
                return;
            }
            ArrayList<Long> num = new ArrayList<>();
            if (n % 2 == 1) {
                for (int i = 2; i <= n; i++) {
                    if (i % 2 == 0)
                        num.add(a[i - 1] + a[i]);
                    else num.add(a[i - 1] - a[i]);
                }
                n--;
            } else for (int i = 1; i <= n; i++) {
                num.add(a[i]);
            }
            n /= 2;
            long tmp1 = 0;
            long tmp2 = 0;
            for (int i = 0; i < num.size(); i++) {
                if (i % 2 == 0) {
                    tmp1 += (C(n - 1, i / 2) * num.get(i)) % MOD;
                } else tmp2 += (C(n - 1, i / 2) * num.get(i)) % MOD;
            }
            if ((n * 2) % 4 == 0) {
                out.println(((tmp1 - tmp2) % MOD + MOD) % MOD);
            } else out.println(((tmp1 + tmp2) % MOD + MOD) % MOD);
        }

        private long C(int n, int k) {
            return Op.mulMod(Op.mulMod(fac[n], Op.inv(fac[k], MOD), MOD), Op.inv(fac[n - k], MOD), MOD);
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public long[] nextLongArray(int length, int stIndex) {
            long[] arr = new long[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextLong();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class Op {
        public static int mulMod(int x, int y, int MOD) {
            return (int) (((long) x * y) % MOD);
        }

        public static int powMod(int x, long p, int MOD) {
            if (p == 0) return 1;
            int t = powMod(x, p / 2, MOD);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t, MOD), x, MOD);
            return mulMod(t, t, MOD);
        }

        public static int inv(int x, int MOD) {
            return powMod(x, MOD - 2, MOD);
        }

    }
}