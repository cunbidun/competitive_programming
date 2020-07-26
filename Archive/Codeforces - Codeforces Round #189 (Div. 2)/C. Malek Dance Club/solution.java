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
        CMalekDanceClub solver = new CMalekDanceClub();
        solver.solve(1, in, out);
        out.close();
    }

    static class CMalekDanceClub {
        private static final int MOD = (int) 1e9 + 7;
        private InputReader in;
        private PrintWriter out;
        private MOD mod = new MOD(MOD);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            String x = in.nextString();
            int ans = 0;
            for (int i = 0; i < x.length(); i++) {
                if (x.charAt(i) == '1') {
                    int tmp = 1;
                    tmp = mod.mulMod(tmp, mod.powMod(2, i));
                    tmp = mod.mulMod(tmp, mod.powMod(2, x.length() - i - 1));
                    tmp = mod.mulMod(tmp, mod.powMod(2, x.length() - i - 1));
                    ans = mod.addMod(ans, tmp);
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

    static class MOD {
        private int MOD;

        public MOD(int MOD) {
            this.MOD = MOD;
        }

        public int addMod(int x, int y) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

        public int mulMod(int x, int y) {
            return (int) (((long) x * y) % MOD);
        }

        public int powMod(int x, long p) {
            if (p == 0) return 1;
            int t = powMod(x, p / 2);
            if ((p & 1) == 1)
                return mulMod(mulMod(t, t), x);
            return mulMod(t, t);
        }

    }
}