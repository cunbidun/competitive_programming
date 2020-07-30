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
        BPairs solver = new BPairs();
        solver.solve(1, in, out);
        out.close();
    }

    static class BPairs {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            PairII[] a = new PairII[m + 1];
            int[] cnt = new int[n + 1];
            ArrayList<PairII> list = new ArrayList<>();
            for (int i = 1; i <= m; i++) {
                a[i] = new PairII(in.nextInt(), in.nextInt());
            }
            int x = a[1].first;
            for (int i = 1; i <= m; i++) {
                if (a[i].first != x && a[i].second != x) {
                    list.add(a[i]);
                }
            }
            for (PairII p : list) {
                cnt[p.first]++;
                cnt[p.second]++;
            }
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == list.size()) {
                    out.println("YES");
                    return;
                }
            }
            list.clear();
            cnt = new int[n + 1];
            x = a[1].second;
            for (int i = 1; i <= m; i++) {
                if (a[i].first != x && a[i].second != x) {
                    list.add(a[i]);
                }
            }
            for (PairII p : list) {
                cnt[p.first]++;
                cnt[p.second]++;
            }
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == list.size()) {
                    out.println("YES");
                    return;
                }
            }
            out.println("NO");
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
}