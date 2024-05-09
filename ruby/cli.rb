# usage: DEBUGGING=1 ruby cli.rb input
require_relative './main'

if ARGV.empty?
  solve(STDIN)
else
  File.open(ARGV[0], 'r') do |io|
    x = io.gets.to_i
    x.times { |_| solve(io) }
  end
end
