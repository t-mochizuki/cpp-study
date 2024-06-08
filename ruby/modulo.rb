class Modulo
  attr_reader :value

  def initialize(x, mod)
    @mod = mod
    @value = x % mod
  end

  def +(other)
    Modulo.new((value + other.value) % @mod, @mod)
  end

  def -(other)
    Modulo.new((value - other.value) % @mod, @mod)
  end

  def *(other)
    Modulo.new((value * other.value) % @mod, @mod)
  end

  def inverse
    x, y = extendedEuclidean(value, @mod)
    return x % @mod
  end

  def /(other)
    Modulo.new((value * other.inverse) % @mod, @mod)
  end

  private

  def extendedEuclidean(a, b, x = 1, y = 0, u = 0, v = 1)
    if b == 0
      return [x, y]
    else
      q, r = a.divmod b
      x -= q * u
      y -= q * v
      return extendedEuclidean(b, r, u, v, x, y)
    end
  end
end
