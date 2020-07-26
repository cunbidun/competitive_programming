import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
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
        DNastyaIsBuyingLunch solver = new DNastyaIsBuyingLunch();
        solver.solve(1, in, out);
        out.close();
    }

    static class DNastyaIsBuyingLunch {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            int[] a = in.nextIntArray(n, 1);
            boolean[] ch = new boolean[n + 1];
            ArrayList<Integer>[] adj = new ArrayList[n + 1];
            ArrayList<PairII> num = new ArrayList<>();
            int[] pos = new int[n + 1];

            for (int i = 1; i <= n; i++) {
                adj[i] = new ArrayList<>();
                pos[a[i]] = i;
            }

            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                adj[u].add(v);
                if (v == a[n]) num.add(new PairII(pos[u], u));
            }
            if (num.size() == 0) {
                out.println(0);
                return;
            }
            for (int i = 1; i <= n; i++) {
                if (adj[i].size() != 0)
                    Collections.sort(adj[i]);
            }
            Collections.sort(num);
            int ans = 0;
            for (int i = num.size() - 1; i >= 0; i--) {
                int cur = num.get(i).second;
                if (adj[cur].size() == 0) {
                    out.println(ans);
                    return;
                }
                int curPos = num.get(i).first;
                boolean f = false;
                for (int j = curPos + 1; j <= n - ans; j++) {
                    if (ch[a[j]]) continue;
                    int bPos = BinarySearch.lowerBound(adj[cur], 0, adj[cur].size() - 1, a[j]);
                    if (bPos == adj[cur].size() || !adj[cur].get(bPos).equals(a[j])) {
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    ch[cur] = true;
                    ans++;
                }
            }
            out.println(ans);
        }

    }

    static class BinarySearch {
        public static int lowerBound(ArrayList<Integer> array, int indexSt, int indexEn, long value) {
            if (value > array.get(indexEn)) return indexEn + 1;
            int low = indexSt;
            int high = indexEn;
            while (low < high) {
                final int mid = (low + high) / 2;
                if (value <= array.get(mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return low;
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
            int[] arr = new int[length + stIndex];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
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