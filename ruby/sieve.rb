class Sieve
  attr_reader :primes
  def initialize(n)
    @primes = []
    factors = Array.new n+1, 0
    factors[0] = -1
    factors[1] = -1
    (2..n).each do |i|
      next if factors[i] != 0
      @primes << i
      factors[i] = i
      (i*i..n).step(i).each do |j|
        if factors[j] == 0
          factors[j] = i
        end
      end
    end
  end
end
