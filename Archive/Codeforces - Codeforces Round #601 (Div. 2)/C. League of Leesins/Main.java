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
        OutputWriter out = new OutputWriter(outputStream);
        Task1255C solver = new Task1255C();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1255C {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int[] cnt = new int[n + 1];
            TreeSet<Integer>[] a = new TreeSet[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = new TreeSet<>();
            }
            for (int i = 1; i <= n - 2; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                int z = in.nextInt();
                a[x].add(y);
                a[x].add(z);
                a[y].add(x);
                a[y].add(z);
                a[z].add(x);
                a[z].add(y);

                cnt[x]++;
                cnt[y]++;
                cnt[z]++;
            }
            int st = 0;
            int nd = 0;
            int ls = 0;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == 1) {
                    st = i;
                    for (int j : a[i])
                        if (cnt[j] == 2) {
                            nd = j;
                            break;
                        }
                    break;
                }
            }
            out.print(st + " " + nd + " ");
            boolean done = false;
            while (true) {
                for (int i : a[st])
                    if (i != ls) {
                        if (a[nd].contains(i)) {
                            out.print(i + " ");
                            if (cnt[i] == 1) done = true;
                            ls = st;
                            st = nd;
                            nd = i;
                            break;
                        }
                    }
                if (done) break;
            }
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

        public void print(String i) {
            out.print(i);
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
}