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
        DTolikAndHisUncle solver = new DTolikAndHisUncle();
        solver.solve(1, in, out);
        out.close();
    }

    static class DTolikAndHisUncle {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            ArrayList<PairII> ans = new ArrayList<>();
            for (int i = 1; i <= n / 2; i++) {
                for (int j = 1; j <= m; j++) {
                    ans.add(new PairII(i, j));
                    ans.add(new PairII(n - i + 1, j));
                }
            }

            int cnt = 0;
            for (int i = 0; i < ans.size(); i++) {
                cnt++;
                if (cnt % 2 == 1)
                    out.println(ans.get(i).first + " " + ans.get(i).second);
                else
                    out.println(ans.get(i).first + " " + (m - ans.get(i).second + 1));

                if (cnt == 2 * m) {
                    cnt = 0;
                }
            }
            if (n % 2 == 1) {
                for (int i = 1; i <= m / 2; i++) {
                    out.println(n / 2 + 1 + " " + i);
                    out.println(n / 2 + 1 + " " + (m - i + 1));
                }
                if (m % 2 == 1) out.println((n / 2 + 1) + " " + (m / 2 + 1));
            }
        }

    }

    static class PairII implements Comparable<PairII> {
        public int first;
        public int second;

        public PairII(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            PairII pair = (PairII) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
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