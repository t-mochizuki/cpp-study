class DisjointSet
  def initialize(n)
    @parent = Array.new n
    n.times { |i| @parent[i] = i }
    @rank = Array.new n, 0
  end

  def find(x)
    return x if @parent[x] == x
    @parent[x] = find(@parent[x]) # pass compression
  end

  def same?(x, y)
    find(x) == find(y)
  end

  def link!(x, y)
    if @rank[x] > @rank[y]
      @parent[y] = x
    else
      @parent[x] = y
      if @rank[x] == @rank[y]
        @rank[y] += 1
      end
    end
  end

  def merge!(x, y)
    rx = find(x)
    ry = find(y)
    return if rx == ry
    link!(rx, ry)
  end
end

