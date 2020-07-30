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
        Task1196E solver = new Task1196E();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1196E {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int q = in.nextInt();
            while (q-- > 0) {
                int b = in.nextInt();
                int w = in.nextInt();
                ArrayList<PairII> ans = new ArrayList<>();
                if (b > w) {
                    for (int i = 1; i <= 2 * w; i++)
                        ans.add(new PairII(2, 2 + i - 1));
                    ans.add(new PairII(2, 1));
                    for (int i = 1; i <= 2 * w; i++)
                        if (i % 2 == 0) {
                            ans.add(new PairII(1, i));
                            ans.add(new PairII(3, i));
                        }
                    if (ans.size() < b + w) out.println("NO");
                    else {
                        out.println("YES");
                        for (int i = 1; i <= b + w; i++)
                            out.println(ans.get(i - 1).first + " " + ans.get(i - 1).second);
                    }
                } else {
                    for (int i = 1; i <= 2 * b; i++)
                        ans.add(new PairII(3, 2 + i - 1));
                    ans.add(new PairII(3, 1));
                    for (int i = 1; i <= 2 * b; i++)
                        if (i % 2 == 0) {
                            ans.add(new PairII(2, i));
                            ans.add(new PairII(4, i));
                        }
                    if (ans.size() < b + w) out.println("NO");
                    else {
                        out.println("YES");
                        for (int i = 1; i <= b + w; i++)
                            out.println(ans.get(i - 1).first + " " + ans.get(i - 1).second);
                    }
                }
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

        public void println(String i) {
            out.println(i);
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