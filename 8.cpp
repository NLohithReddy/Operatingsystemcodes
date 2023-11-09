#include <iostream>
#include <algorithm>
#include <cmath>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void FCFS(int arr[], int head, int size) {
    int seek_count = 0;
    int distance, current_track;
    for (int i = 0; i < size; i++) {
        current_track = arr[i];
        distance = std::abs(current_track - head);
        seek_count += distance;
        head = current_track;
    }
    std::cout << "Total Seek Time FCFS: " << seek_count << std::endl;
}

void SSTF(int arr[], int head, int size) {
    int seek_count = 0;
    int visited[size];
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int min = 1e9;
        int min_index;
        for (int j = 0; j < size; j++) {
            if (!visited[j] && std::abs(head - arr[j]) < min) {
                min = std::abs(head - arr[j]);
                min_index = j;
            }
        }
        visited[min_index] = 1;
        seek_count += min;
        head = arr[min_index];
    }
    std::cout << "Total Seek Time SSTF: " << seek_count << std::endl;
}

void SCAN(int arr[], int head, int size, int direction, int disk_size) {
    int seek_count = 0;
    int distance;
    int current_track;
    int left[size], right[size];
    int left_count = 0, right_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < head) {
            left[left_count++] = arr[i];
        } else if (arr[i] > head) {
            right[right_count++] = arr[i];
        }
    }
    std::sort(left, left + left_count);
    std::sort(right, right + right_count);
    int run = 2;
    while (run--) {
        if (direction == 1) {
            for (int i = left_count - 1; i >= 0; i--) {
                current_track = left[i];
                distance = std::abs(current_track - head);
                seek_count += distance;
                head = current_track;
            }
            direction = 0;
        } else if (direction == 0) {
            for (int i = 0; i < right_count; i++) {
                current_track = right[i];
                distance = std::abs(current_track - head);
                seek_count += distance;
                head = current_track;
            }
            direction = 1;
        }
    }
    std::cout << "Total Seek Time SCAN: " << seek_count << std::endl;
}

int main() {
    int size, head, direction, disk_size;
    std::cout << "Enter the size of the queue: ";
    std::cin >> size;
    int arr[size];
    std::cout << "Enter the queue: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    std::cout << "Enter the initial head position: ";
    std::cin >> head;
    std::cout << "Enter the direction (0 for left, 1 for right): ";
    std::cin >> direction;
    std::cout << "Enter the disk size: ";
    std::cin >> disk_size;

    FCFS(arr, head, size);
    SSTF(arr, head, size);
    SCAN(arr, head, size, direction, disk_size);

    return 0;
}

