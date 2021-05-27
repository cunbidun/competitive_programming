import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        OutputWriter out = new OutputWriter(outputStream);
        D2SubmarineInTheRybinskSeaHardEdition solver = new D2SubmarineInTheRybinskSeaHardEdition();
        solver.solve(1, in, out);
        out.close();
    }

    static class D2SubmarineInTheRybinskSeaHardEdition {
        private static final int MOD = 998244353;
        private InputReader in;
        private OutputWriter out;
        private ArrayList<Integer>[] list = new ArrayList[11];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            for (int i = 1; i <= 10; i++) {
                list[i] = new ArrayList<>();
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] < 10) list[1].add(a[i]);
                else if (a[i] < 100) list[2].add(a[i]);
                else if (a[i] < 1000) list[3].add(a[i]);
                else if (a[i] < 10000) list[4].add(a[i]);
                else if (a[i] < 100000) list[5].add(a[i]);
                else if (a[i] < 1000000) list[6].add(a[i]);
                else if (a[i] < 10000000) list[7].add(a[i]);
                else if (a[i] < 100000000) list[8].add(a[i]);
                else if (a[i] < 1000000000) list[9].add(a[i]);
                else list[10].add(a[i]);
            }
            int ans = 0;
            for (int i = 1; i <= 10; i++) {
                for (int j = 1; j <= 10; j++)
                    if (i != j && list[i].size() != 0 && list[j].size() != 0) {
                        ans = Op.addMod(ans, sol(i, j), MOD);
                    }
            }
            int res = 0;
            for (int first = 1; first <= 10; first++) {
                for (int i : list[first]) {
                    int pos = 0;
                    int tmp = i;
                    while (tmp > 0) {
                        int di = tmp % 10;
                        int pow = Op.mulMod(Op.powMod(10, pos, MOD), list[first].size(), MOD);
                        res = Op.addMod(res, Op.mulMod(pow, di, MOD), MOD);
                        pow = Op.mulMod(Op.powMod(10, pos + 1, MOD), list[first].size(), MOD);
                        res = Op.addMod(res, Op.mulMod(pow, di, MOD), MOD);
                        pos += 2;
                        tmp /= 10;
                    }
                }
            }
//        out.println(res);
            out.println(Op.addMod(ans, res, MOD));
        }

        private int sol(int first, int second) {
            int res = 0;
            if (first > second) {
                long cst1 = pow(second);
                long cst2 = pow(second * 2);
                for (int i : list[first]) {
                    int pos = 0;
                    int tmp = (int) ((i / cst1 * cst2) % MOD);
                    tmp = Op.mulMod(tmp, list[second].size(), MOD);
                    res = Op.addMod(res, tmp, MOD);
                }
                for (int i : list[first]) {
                    int pos = 1;
                    int tmp = (int) (i % cst1);
                    while (tmp > 0) {
                        int di = tmp % 10;
                        int pow = Op.mulMod(Op.powMod(10, pos, MOD), list[second].size(), MOD);
                        res = Op.addMod(res, Op.mulMod(pow, di, MOD), MOD);
                        pos += 2;
                        tmp /= 10;
                    }
                }
                for (int i : list[second]) {
                    int pos = 0;
                    int tmp = i;
                    while (tmp > 0) {
                        int di = tmp % 10;
                        int pow = Op.mulMod(Op.powMod(10, pos, MOD), list[first].size(), MOD);
                        res = Op.addMod(res, Op.mulMod(pow, di, MOD), MOD);
                        pos += 2;
                        tmp /= 10;
                    }
                }
            } else if (second > first) {
                long cst1 = pow(first);
                long cst2 = pow(first * 2);
                for (int i : list[second]) {
                    int pos = 0;
                    int tmp = (int) ((i / cst1 * cst2) % MOD);
                    tmp = Op.mulMod(tmp, list[first].size(), MOD);
                    res = Op.addMod(res, tmp, MOD);
                }
                for (int i : list[second]) {
                    int pos = 0;
                    int tmp = (int) (i % cst1);
                    while (tmp > 0) {
                        int di = tmp % 10;
                        int pow = Op.mulMod(Op.powMod(10, pos, MOD), list[first].size(), MOD);
                        res = Op.addMod(res, Op.mulMod(pow, di, MOD), MOD);
                        pos += 2;
                        tmp /= 10;
                    }
                }
                for (int i : list[first]) {
                    int pos = 1;
                    int tmp = i;
                    while (tmp > 0) {
                        int di = tmp % 10;
                        int pow = Op.mulMod(Op.powMod(10, pos, MOD), list[second].size(), MOD);
                        res = Op.addMod(res, Op.mulMod(pow, di, MOD), MOD);
                        pos += 2;
                        tmp /= 10;
                    }
                }
            }
            return res;
        }

        public long pow(long p) {
            if (p == 0) return 1;
            long t = pow(p / 2);
            if ((p & 1) == 1)
                return t * t * 10;
            return t * t;
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
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

    static class Op {
        public static int addMod(int x, int y, int MOD) {
            return ((x + y) >= MOD ? x + y - MOD : x + y);
        }

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

    }

    static class OutputWriter {
        private final PrintWriter out;

        public OutputWriter(OutputStream outputStream) {
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.out = new PrintWriter(writer);
        }

        public void close() {
            out.close();
        }

        public void println(int i) {
            out.println(i);
        }

    }
}