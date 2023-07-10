require_relative './main'

if ARGV.empty?
  solve(STDIN)
else
  File.open('input', 'r') do |r|
    x = r.gets.to_i
    x.times { |_| solve(r) }
  end
end
