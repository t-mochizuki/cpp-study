class DisjointSet
  attr_reader :leader
  def initialize(n)
    @leader = Array.new n, -1
  end

  def find(x)
    return x if leader[x] < 0
    leader[x] = find(leader[x]) # pass compression
  end

  def size(x)
    -leader[find(x)]
  end

  def same?(x, y)
    find(x) == find(y)
  end

  def link!(x, y)
    x,y=y,x if leader[x] > leader[y]
    leader[x] += leader[y]
    leader[y] = x
  end

  def merge!(x, y)
    rx = find(x)
    ry = find(y)
    return false if rx == ry
    link!(rx, ry)
    true
  end
end
