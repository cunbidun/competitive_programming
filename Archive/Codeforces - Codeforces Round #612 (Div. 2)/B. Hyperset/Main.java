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
        Task1287B solver = new Task1287B();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1287B {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            TreeSet<String> set = new TreeSet<>();
            String[] a = new String[n + 1];
            for (int i = 1; i <= n; i++) {
                a[i] = in.nextString();
                set.add(a[i]);
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++)
                    if (i != j) {
                        StringBuilder res = new StringBuilder();
                        for (int k = 0; k < m; k++) {
                            if (a[i].charAt(k) == a[j].charAt(k)) {
                                res.append(a[i].charAt(k));
                            } else {
                                if (a[i].charAt(k) == 'S' && a[j].charAt(k) == 'E') {
                                    res.append('T');
                                } else if (a[i].charAt(k) == 'T' && a[j].charAt(k) == 'E') {
                                    res.append('S');
                                } else if (a[i].charAt(k) == 'S' && a[j].charAt(k) == 'T') {
                                    res.append('E');
                                } else if (a[i].charAt(k) == 'E' && a[j].charAt(k) == 'S') {
                                    res.append('T');
                                } else if (a[i].charAt(k) == 'E' && a[j].charAt(k) == 'T') {
                                    res.append('S');
                                } else if (a[i].charAt(k) == 'T' && a[j].charAt(k) == 'S') {
                                    res.append('E');
                                }
                            }
                        }
//                if (res.equals(a[i]) || res.equals(a[j]))
//                    continue;
                        if (set.contains(res.toString())) {
//                    out.println(a[i] + " " + a[j] + " " + res);
                            ans++;
                        }
                    }
            }
            out.println(ans / 3);
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

        public String nextString() {
            int c;
            while (isSpaceChar(c = read())) ;
            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);
            while (!isSpaceChar(c = read()))
                result.appendCodePoint(c);
            return result.toString();
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}