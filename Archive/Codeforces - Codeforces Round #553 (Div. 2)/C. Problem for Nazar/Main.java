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
        CProblemForNazar solver = new CProblemForNazar();
        solver.solve(1, in, out);
        out.close();
    }

    static class CProblemForNazar {
        private static final long MOD = (long) 1e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private MODLong mod = new MODLong(MOD);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            long l = in.nextLong();
            long r = in.nextLong();
            out.println(mod.subMod(cal(r), cal(l - 1)));
        }

        private long cal(long m) {
            long cur = 0;
            long numOdd = 0;
            long numEven = 0;
            long cnt = 0;

            while (cur <= m) {
                cur += ((long) 1 << cnt);
                if (cur > m) break;
                if (cnt % 2 == 0)
                    numOdd += (long) 1 << cnt;
                else numEven += (long) 1 << cnt;
                cnt++;

            }
            // 1 2 4 3 5 7 9 8 10

            if (cnt % 2 == 1) numEven = m - numOdd;
            else numOdd = m - numEven;
//        out.println(m + " " + numOdd + " " + numEven);
            long tmpE = mod.mulMod(numEven * 2 + 2, numEven);
            tmpE = mod.mulMod(tmpE, mod.inv(2));

            long tmpO = mod.mulMod(numOdd * 2 - 1 + 1, numOdd);
            tmpO = mod.mulMod(tmpO, mod.inv(2));

            return mod.addMod(tmpE, tmpO);
        }

    }

    static class MODLong {
        private long MOD;

        public MODLong(long MOD) {
            this.MOD = MOD;
        }

        public long addMod(long x, long y) {
            return ((x + y) % MOD);
        }

        public long subMod(long x, long y) {
            return ((x - y) % MOD + MOD) % MOD;
        }

        public long mulMod(long x, long y) {
            return (((x % MOD) * (y % MOD)) % MOD);
        }

        public long powMod(long x, long p) {
            if (p == 0) return 1;
            long t = powMod(x, p / 2);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t), x);
            return mulMod(t, t);
        }

        public long inv(long x) {
            return powMod(x, MOD - 2);
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}