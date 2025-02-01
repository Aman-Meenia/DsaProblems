g++ -std=c++17 test.cpp -o test
g++ -std=c++17 brute.cpp -o brute
# g++ -std=c++17 gen.cpp -o gen   # For  array
g++ -std=c++17 gen_str.cpp -o gen_str # For string
# g++ -std=c++17 gen_tree.cpp -o gen_tree # For Tree

for((i = 1; ; ++i)); do
  # echo "Testcase:" $i
  # ./gen $i > in    # For array
  ./gen_str $i > in   # For string
  # ./gen_tree $i > in  # For Tree
  ./test < in > output
  ./brute < in > bruteOutput
  diff -w output bruteOutput || break   # -w ignore spaces
  echo "passed test: " $i
done

echo "WA on the following test:"
cat in
echo "Your answer is:"
cat output
echo "Correct answer is:"
cat bruteOutput
