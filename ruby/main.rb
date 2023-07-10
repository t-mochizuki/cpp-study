def solve(r)
  a = r.gets.to_i
  b,c= r.gets.chomp.split(" ").map(&:to_i)
  s = r.gets.chomp
  print("#{a+b+c} #{s}\n")
end

# solve(STDIN)
