import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.TreeMap;
import java.util.InputMismatchException;
import java.io.IOException;
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
        CLorenzoVonMatterhorn solver = new CLorenzoVonMatterhorn();
        solver.solve(1, in, out);
        out.close();
    }

    static class CLorenzoVonMatterhorn {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int q = in.nextInt();
            TreeMap<Long, Long> road = new TreeMap<>();

            while (q-- > 0) {
                int cmd = in.nextInt();
                if (cmd == 1) {
                    long u = in.nextLong();
                    long v = in.nextLong();
                    long w = in.nextLong();
                    while (u != v) {
                        if (u > v) {
                            long tmp = u;
                            u = v;
                            v = tmp;
                        }
                        if (!road.containsKey(v)) road.put(v, w);
                        else road.put(v, road.get(v) + w);
                        v /= 2;
                    }
                } else {
                    long ans = 0;
                    long u = in.nextLong();
                    long v = in.nextLong();
                    while (u != v) {
                        if (u > v) {
                            long tmp = u;
                            u = v;
                            v = tmp;
                        }
                        if (road.containsKey(v)) ans += road.get(v);
                        v /= 2;
                    }
                    out.println(ans);
                }
            }
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

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}