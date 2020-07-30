import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        Task814D solver = new Task814D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task814D {
        private InputReader in;
        private OutputWriter out;
        private TripIII[] a = new TripIII[1010];
        private ArrayList<Integer>[] p = new ArrayList[1010];

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            for (int i = 1; i <= n; i++) {
                p[i] = new ArrayList<>();
                a[i] = new TripIII(in.nextInt(), in.nextInt(), in.nextInt());
            }
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    if (ch(i, j) == 0) p[j].add(i);
                    else if (ch(i, j) == 1) p[i].add(j);
            long ans = 0;
            for (int i = 1; i <= n; i++) {
                if (p[i].size() == 0 || p[i].size() % 2 == 1) {
                    ans += (long) a[i].third * a[i].third;
                } else ans -= (long) a[i].third * a[i].third;
            }
            out.println(ans * Math.PI);
        }

        private int ch(int i, int j) {
            long dis = ((long) a[i].first - a[j].first) * (a[i].first - a[j].first) + ((long) a[i].second - a[j].second) * (a[i].second - a[j].second);
            if (a[i].third > a[j].third) {
                if (dis < (long) a[i].third * a[i].third) return 0;
                if (dis < (long) a[j].third * a[j].third) return 1;
            } else {
                if (dis < (long) a[j].third * a[j].third) return 1;
                if (dis < (long) a[i].third * a[i].third) return 0;
            }
            return 2;
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

        public void println(double i) {
            out.println(i);
        }

    }
}