//: [Previous](@previous)

import Foundation


func thirdMax(_ nums: [Int]) -> Int {
    var max1 = Int.min
    var max2 = Int.min
    var max3 = Int.min
    
    let count = nums.count
    for i in 0...count {
        let item = nums[i]
        
        if item == max3 || item == max2 || item == max1 {
            continue
        }
        
        if item > max3 {
            max1 = max2
            max2 = max3
            max3 = item;
        } else if item > max2 {
            max1 = max2
            max2 = item
        } else if item > max1 {
            max1 = item
        }
    }
    return max1 == Int.min ? max3 : max1
}

//33. Search in Rotated Sorted Array

func search(_ nums: [Int], _ target: Int) -> Int {
    var left = 0
    var right = nums.count - 1
    
    while left <= right {
        var mid = (right - left) / 2 + left
        if nums[mid] ==  target {
            return mid
        }
        if nums[mid] > nums[left] {
            if target >= nums[left] && target < nums[mid] {
                right = mid - 1
            } else {
                left = mid + 1
            }
        } else {
            if target > nums[mid] && target <= nums[right] {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
    }
    return - 1
}

func search_d(_ nums: [Int], _ target: Int) -> Int {
    var left = 0
    var right = nums.count - 1
    
    while left <= right {
        var mid = (right - left) / 2 + left
        if nums[mid] ==  target {
            return mid
        }
        if nums[mid] > nums[left] {
            if target >= nums[left] && target < nums[mid] {
                right = mid - 1
            } else {
                left = mid + 1
            }
        } else {
            if target > nums[mid] && target <= nums[right] {
                left = mid + 1
            } else {
                right = mid - 1
            }
        } else {
            left += 1
        }
    }
    return - 1
}
