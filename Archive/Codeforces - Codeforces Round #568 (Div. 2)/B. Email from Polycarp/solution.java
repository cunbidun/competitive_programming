import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        BEmailFromPolycarp solver = new BEmailFromPolycarp();
        solver.solve(1, in, out);
        out.close();
    }

    static class BEmailFromPolycarp {
        private InputReader in;
        private PrintWriter out;
        private PrinterUtil printer;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            this.printer = new PrinterUtil(out);

            int n = in.nextInt();
            while (n-- > 0) {
                String f = in.nextString();
                String s = in.nextString();
                ArrayList<PairCI> c1 = new ArrayList<>();
                ArrayList<PairCI> c2 = new ArrayList<>();
                int cnt = 1;
                for (int i = 1; i < f.length(); i++) {
                    if (f.charAt(i) != f.charAt(i - 1)) {
                        c1.add(new PairCI(f.charAt(i - 1), cnt));
                        cnt = 1;
                    } else cnt++;
                }
                c1.add(new PairCI(f.charAt(f.length() - 1), cnt));

                cnt = 1;
                for (int i = 1; i < s.length(); i++) {
                    if (s.charAt(i) != s.charAt(i - 1)) {
                        c2.add(new PairCI(s.charAt(i - 1), cnt));
                        cnt = 1;
                    } else cnt++;
                }
                c2.add(new PairCI(s.charAt(s.length() - 1), cnt));

                if (c1.size() != c2.size()) out.println("NO");
                else {
                    boolean d = false;
                    for (int i = 0; i < c1.size(); i++) {
                        PairCI p1 = c1.get(i);
                        PairCI p2 = c2.get(i);
                        if (p1.first != p2.first || p1.second > p2.second) {
                            d = true;
                            break;
                        }
                    }
                    if (d) {
                        out.println("NO");
                    } else
                        out.println("YES");
                }
            }
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

    static class PairCI implements Comparable<PairCI> {
        public char first;
        public int second;

        public PairCI(char first, int second) {
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

        public int compareTo(PairCI o) {
            int value = Character.compare(first, o.first);
            if (value != 0) {
                return value;
            }
            return Integer.compare(second, o.second);
        }

    }

    static class PrinterUtil {
        private PrintWriter out;

        public PrinterUtil(PrintWriter out) {
            this.out = out;
        }

    }
}