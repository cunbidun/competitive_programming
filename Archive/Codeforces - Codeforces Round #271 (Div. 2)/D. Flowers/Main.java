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
        DFlowers solver = new DFlowers();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFlowers {
        private static final int MOD = (int) 1e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private MOD mod = new MOD(MOD);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int t = in.nextInt();
            int k = in.nextInt();
            int[] f = new int[100010];
            for (int i = 1; i < k; i++) f[i] = 1;
            f[0] = 1;
            for (int i = k; i <= 100000; i++) {
                f[i] = mod.addMod(f[i - 1], f[i - k]);
            }
            f[0] = 0;

            for (int i = 1; i <= 100000; i++) {
                f[i] = mod.addMod(f[i - 1], f[i]);
            }
            for (int i = 1; i <= t; i++) {
                int l = in.nextInt();
                int r = in.nextInt();
                out.println(mod.subMod(f[r], f[l - 1]));
            }
        }

    }

    static class MOD {
        private int MOD;

        public MOD(int MOD) {
            this.MOD = MOD;
        }

        public int addMod(int x, int y) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public int subMod(int x, int y) {
            return ((x - y) < 0 ? x - y + MOD : x - y);
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