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
        Task1270D solver = new Task1270D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1270D {
        private InputReader in;
        private OutputWriter out;
        int n;
        int k;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();
            k = in.nextInt();
            PairII init = ask(k + 1);

            int cnt = 0;
            boolean isGreater = true;
            for (int i = 1; i <= k; i++)
                if (i != init.first) {
                    PairII cur = ask(i);
                    if (cur.second == init.second) {
                        cnt++;
                    } else {
                        if (cur.second < init.second) {
                            isGreater = false;
                        }
                    }
                }
            if (cnt == k - 1) {
                for (int i = 1; i <= k; i++)
                    if (i != init.first) {
                        PairII last = ask(init.first);
                        if (last.second < init.second) {
                            out.println("! " + k);
                        } else
                            out.println("! " + 1);
                        out.flush();
                        return;
                    }
            }
            if (isGreater)
                out.println("! " + (k - cnt));
            else
                out.println("! " + (cnt + 1));
            out.flush();
        }

        PairII ask(int p) {
            out.print("? ");
            for (int i = 1; i <= k + 1; i++)
                if (i != p) {
                    out.print(i + " ");
                }
            out.println("");
            out.flush();
            return new PairII(in.nextInt(), in.nextInt());
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

        public void flush() {
            out.flush();
        }

        public void print(String i) {
            out.print(i);
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
}