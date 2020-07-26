import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.AbstractCollection;
import java.util.TreeMap;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        Task1206D solver = new Task1206D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1206D {
        private static final int INF = (int) 2e9 + 7;
        private InputReader in;
        private OutputWriter out;
        private TreeSet<PairII>[] adj;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            long[] a = in.nextLongArray(n, 1);
            ArrayList<Integer>[] list = new ArrayList[65];
            for (int i = 0; i <= 60; i++) {
                list[i] = new ArrayList<>();
                for (int j = 1; j <= n; j++) if (BitWise.isOn(a[j], i)) list[i].add(j);
            }
            for (int i = 0; i <= 60; i++)
                if (list[i].size() >= 3) {
                    out.println(3);
                    return;
                }
            adj = new TreeSet[151];
            for (int i = 1; i <= 150; i++) adj[i] = new TreeSet<>();
            TreeMap<Long, Integer> map = new TreeMap<>();
            for (int i = 0; i <= 60; i++)
                if (list[i].size() == 2 && !list[i].get(0).equals(list[i].get(1))) {
                    long u = list[i].get(0);
                    long v = list[i].get(1);
                    if (!map.containsKey(u)) map.put(u, map.size() + 1);
                    if (!map.containsKey(v)) map.put(v, map.size() + 1);
                    int x0 = map.get(u);
                    int x1 = map.get(v);
                    adj[x0].add(new PairII(1, x1));
                    adj[x1].add(new PairII(1, x0));
                }
            int ans = INF;
            for (int i = 1; i <= 150; i++)
                for (PairII j : adj[i])
                    if (adj[i].size() > 0) ans = MaxMin.Min(ans, dijkstra(i, j.second) + 1);
            if (ans == INF)
                out.println(-1);
            else
                out.println(ans);
        }

        private int dijkstra(int start, int end) {
            //adj: PairII (first distance, second vertex)
            int n = 150;
            int[] d = new int[n + 1];
            PriorityQueue<PairII> pq = new PriorityQueue<>(); // can be changed to PairII.
            for (int i = 1; i <= n; i++) d[i] = INF - 1; //d: distance from start vertex to all other vertex.
            d[start] = 0;
            pq.add(new PairII(0, start));
            while (!pq.isEmpty()) {
                int u = pq.peek().second;
                int du = pq.peek().first;
                pq.poll();
                if (du > d[u]) continue;
                for (PairII p : adj[u]) {
                    int v = p.second;
                    if ((u == start && v == end) || (u == end && v == start)) continue;
                    int uv = p.first;
                    if (d[v] > du + uv) {
                        d[v] = du + uv;
                        pq.add(new PairII(d[v], v));
                    }
                }
            }
            return d[end];
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

    static class MaxMin {
        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }

    static class BitWise {
        public static boolean isOn(long x, int pos) {
            return ((x >> pos) & 1) == 1;
        }

    }
}