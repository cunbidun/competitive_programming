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
import java.util.List;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
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
        Task1196F solver = new Task1196F();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1196F {
        private static final long INFLL = (long) 9e18 + 7;
        private InputReader in;
        private OutputWriter out;
        private ArrayList<PairII>[] adj;
        private ArrayList<Long> list = new ArrayList<>();
        private TreeSet<PairII> set = new TreeSet<>();
        private ArrayList<TripIII> edgeList = new ArrayList<>();
        private long[] d;
        private int n;
        private int k;
        private long cur;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            int m = in.nextInt();
            k = in.nextInt();
            adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
            for (int i = 1; i <= m; i++) {
                int u = in.nextInt();
                int v = in.nextInt();
                int w = in.nextInt();
                edgeList.add(new TripIII(w, u, v));
            }
            Collections.sort(edgeList);
            for (int i = 0; i < MaxMin.Min(k, m); i++) {
                int u = edgeList.get(i).second;
                int v = edgeList.get(i).third;
                int w = edgeList.get(i).first;
                adj[u].add(new PairII(w, v));
                adj[v].add(new PairII(w, u));
            }
            d = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                d[i] = INFLL;
            }
            cur = INFLL;
            int i;
            for (i = 1; i <= n; i++) {
                dijkstra(i);
                if (list.size() > k) break;
            }

            Collections.sort(list);
            cur = list.get(k - 1);
            list.subList(k, list.size()).clear();
            i++;

            for (; i <= n; i++) {
                dijkstra(i);
                if (list.size() > 5000) {
                    Collections.sort(list);
                    list.subList(k, list.size()).clear();
                    cur = list.get(k - 1);
                }
            }

            Collections.sort(list);
            cur = list.get(k - 1);

            out.println(cur);
        }

        private void dijkstra(int start) {
            //adj: PairII (first distance, second vertex)
            PriorityQueue<PairLI> pq = new PriorityQueue<>(); // can be changed to PairII.
            d[start] = 0;
            ArrayList<Integer> pos = new ArrayList<>();
            pq.add(new PairLI(0, start));
            pos.add(start);
            int cnt = 0;
            while (!pq.isEmpty()) {
                int u = pq.peek().second;
                long du = pq.peek().first;
                pq.poll();
                if (du > d[u]) continue;

                PairII tmp = new PairII(MaxMin.Min(start, u), MaxMin.Max(start, u));
                if (cnt != 0 && du < cur && !set.contains(tmp)) {
                    list.add(du);
                    set.add(tmp);
                }
                cnt++;
                if (cnt > k || du >= cur) {
                    for (int i : pos) d[i] = INFLL;
                    return;
                }
                for (PairII p : adj[u]) {
                    int v = p.second;
                    long uv = p.first;
                    if (d[v] > du + uv) {
                        d[v] = du + uv;
                        pos.add(v);
                        pq.add(new PairLI(d[v], v));
                    }
                }
            }
            for (int i : pos) d[i] = INFLL;
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

    static class TripIII implements Comparable<TripIII> {
        public int first;
        public int second;
        public int third;

        public TripIII(int first, int second, int third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }

            TripIII trip = (TripIII) o;

            return first == trip.first && second == trip.second && third == trip.third;
        }

        public String toString() {
            return "(" + first + "," + second + "," + third + ")";
        }

        public int compareTo(TripIII o) {
            int value = Integer.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            value = Integer.compare(second, o.second);
            if (value != 0) {
                return value;
            }
            return Integer.compare(third, o.third);
        }

    }

    static class PairLI implements Comparable<PairLI> {
        public long first;
        public int second;

        public PairLI(long first, int second) {
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

            PairLI pair = (PairLI) o;

            return first == pair.first && second == pair.second;
        }

        public String toString() {
            return "(" + first + "," + second + ")";
        }

        public int compareTo(PairLI o) {
            int value = Long.compare(first, o.first);
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

        public void println(long i) {
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }

    static class MaxMin {
        public static <T extends Comparable<T>> T Max(T x, T y) {
            T max = x;
            if (y.compareTo(max) > 0) max = y;
            return max;
        }

        public static <T extends Comparable<T>> T Min(T x, T y) {
            T min = x;
            if (y.compareTo(min) < 0) min = y;
            return min;
        }

    }
}