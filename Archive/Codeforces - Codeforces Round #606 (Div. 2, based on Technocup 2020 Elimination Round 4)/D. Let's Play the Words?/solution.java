import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
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
        Task1277D solver = new Task1277D();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task1277D {
        private InputReader in;
        private OutputWriter out;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            this.in = in;
            this.out = out;
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt();
                TreeSet<String> set = new TreeSet<>();
                String[] s = new String[n + 1];
                int C10 = 0;
                int C01 = 0;
                boolean ch0 = false;
                boolean ch1 = false;
                boolean[] ch = new boolean[n + 1];

                for (int i = 1; i <= n; i++) {
                    s[i] = in.nextString();
                    set.add(s[i]);
                }
                for (int i = 1; i <= n; i++) {
                    if (s[i].charAt(0) != s[i].charAt(s[i].length() - 1)) {
                        if (s[i].charAt(0) == '1') C10++;
                        else C01++;
                        if (!set.contains(new StringBuilder(s[i]).reverse().toString())) ch[i] = true;
                    } else if (s[i].charAt(0) == '0') ch0 = true;
                    else ch1 = true;
                }
                if (C01 == 0 && C10 == 0 && (ch0 && ch1)) {
                    out.println(-1);
                    continue;
                }
                int min = MaxMin.Min(C10, C01);
                int max = MaxMin.Max(C10, C01);
                ArrayList<Integer> ans = new ArrayList<>();
                boolean f = false;
                if (C10 > C01) f = true;
                for (int i = 1; i <= n; i++) {
                    if (ch[i] && max - min > 1) {
                        if ((f && s[i].charAt(0) == '1') || (!f && s[i].charAt(0) == '0')) {
                            max--;
                            min++;
                            ans.add(i);
                        }
                    }
                    if (max - min <= 1) break;
                }
                if (max - min > 1) {
                    out.println(-1);
                    continue;
                }
                out.println(ans.size());
                out.println(ans);
            }
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

        public void print(ArrayList<Integer> a) {
            for (int i : a) out.print(i + " ");
        }

        public void println(ArrayList<Integer> a) {
            print(a);
            out.println();
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