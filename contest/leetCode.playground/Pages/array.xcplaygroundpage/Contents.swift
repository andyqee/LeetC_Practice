//: [Previous](@previous)

import Foundation

public class Interval {
    public var start: Int
    public var end: Int
    public init(_ start: Int, _ end: Int) {
        self.start = start
        self.end = end
    }
}


func merge(_ intervals: [Interval]) -> [Interval] {
    if intervals.count < 2 {
        return intervals
    }
    
    var result = [Interval]()
    var sortedIntervals = intervals.sorted { (item1, item2) -> Bool in
        return item1.start < item2.start
    }
    
    var cur = sortedIntervals[0]
    var next : Interval
    let count = intervals.count
    for i in 1..<count {
        next = sortedIntervals[i]
        if(cur.end >= next.start) {
            cur.end = max(cur.end, next.end)
        } else {
            result.append(cur)
            cur = next
        }
    }
    result.append(cur)
    return result
}

//let a = Interval(1,4)
//let b = Interval(0,4)
//let res = merge([a,b])


func findMin(_ nums: [Int]) -> Int {
    if nums.count <= 1 {
        return nums.first!
    }
    var left = 0
    var right = nums.count - 1
    
    while left < right {
        var mid = (right - left) / 2 + left
        if(nums[mid] > nums[right]) {
            left = mid + 1
        } else if(nums[mid] < nums[right]){
            right = mid
        }
    }
    return nums[left]
}

//let a = findMin([1, 2, 3])












