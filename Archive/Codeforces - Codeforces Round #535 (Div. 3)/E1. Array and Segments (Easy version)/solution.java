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
        E1ArrayAndSegmentsEasyVersion solver = new E1ArrayAndSegmentsEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class E1ArrayAndSegmentsEasyVersion {
        static final int MAXA = (int) 3e2 + 10;
        private PairIntInt[] seg = new PairIntInt[MAXA];
        private int[] a = new int[MAXA];
        ArrayList<Integer>[] end = new ArrayList[MAXA];
        ArrayList<Integer>[] start = new ArrayList[MAXA];
        ArrayList<Integer> res = new ArrayList<>();
        int ans;
        int[][] f = new int[MAXA][MAXA];
        int[][] f1 = new int[MAXA][MAXA];

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            for (int i = 0; i <= n + 1; i++) {
                start[i] = new ArrayList<>();
                end[i] = new ArrayList<>();
            }
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 1; i <= m; i++) {
                seg[i] = new PairIntInt(in.nextInt(), in.nextInt());
                start[seg[i].first].add(i);
                end[seg[i].second].add(i);

            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    int cur = 0;
                    for (int k = 0; k < end[i - 1].size(); k++) {
                        if (seg[end[i - 1].get(k)].first <= j && seg[end[i - 1].get(k)].second >= j) cur++;
                    }
                    f[i][j] = cur;
                    f[i][j] += f[i - 1][j];
                }
            }
            for (int i = n; i >= 1; i--) {
                for (int j = n; j > i; j--) {
                    int cur = 0;
                    for (int k = 0; k < start[i + 1].size(); k++) {
                        if (seg[start[i + 1].get(k)].second >= j && seg[start[i + 1].get(k)].first <= j) cur++;
                    }
                    f1[i][j] = cur;
                    f1[i][j] += f1[i + 1][j];
                }
            }

            int posI = 0, posJ = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    if (ans < a[i] - a[j] + f[i][j]) {
                        ans = a[i] - a[j] + f[i][j];
                        posI = i;
                        posJ = j;
                    }
                }
            }

            // out.println(posI + " "+ posJ);
            for (int i = n; i >= 1; i--) {
                for (int j = n; j >= i; j--) {
                    if (ans < a[i] - a[j] + f1[i][j]) {
                        ans = a[i] - a[j] + f1[i][j];
                        posI = i;
                        posJ = j;
                    }
                }
            }
            // out.println(posI + " "+ posJ);
            for (int i = 1; i <= m; i++) {
                if (posI >= posJ) {
                    if (seg[i].first <= posJ && seg[i].second >= posJ && seg[i].second < posI)
                        res.add(i);
                } else if (seg[i].first > posI && seg[i].first <= posJ && seg[i].second >= posJ)
                    res.add(i);
            }
            out.println(ans);
            out.println(res.size());
            for (int i = 0; i < res.size(); i++) out.print(res.get(i) + " ");
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

    static class PairIntInt implements Comparable<PairIntInt> {
        public int first;
        public int second;

        public PairIntInt(int first, int second) {
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

            PairIntInt pair = (PairIntInt) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairIntInt o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }
}