import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Collections;
import java.util.TreeSet;
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
        ESegmentsRemoval solver = new ESegmentsRemoval();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESegmentsRemoval {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;

            int n = in.nextInt();
            int[] a = in.nextIntArray(n, 1);
            int cur = 1;
            int last = 1;
            TreeSet<PairII> set = new TreeSet<>(Collections.reverseOrder());
            TreeSet<PairII> pos = new TreeSet<>();

            for (int i = 2; i <= n; i++) {
                if (a[i] == a[i - 1]) {
                    cur++;
                } else {
                    set.add(new PairII(cur, -1 * last));
                    pos.add(new PairII(last, cur));
                    cur = 1;
                    last = i;
                }
            }
            set.add(new PairII(cur, -1 * last));
            pos.add(new PairII(last, cur));
            int ans = 0;


            while (!set.isEmpty()) {
                PairII curMax = set.first();
                set.remove(curMax);
                PairII tmp = new PairII(-1 * curMax.second, curMax.first);
                pos.remove(tmp);
                PairII next = pos.higher(tmp);
                PairII pre = pos.lower(tmp);
                if (next != null && pre != null) {
                    if (a[next.first] == a[pre.first]) {
                        pos.remove(next);
                        pos.remove(pre);
                        pos.add(new PairII(pre.first, pre.second + next.second));
                        set.remove(new PairII(next.second, -1 * next.first));
                        set.remove(new PairII(pre.second, -1 * pre.first));
                        set.add(new PairII(pre.second + next.second, -1 * pre.first));
                    }
                }
                ans++;
            }
            out.println(ans);
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
}