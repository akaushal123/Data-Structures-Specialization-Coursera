#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::vector;
using std::cin;
using std::cout;

class Thread{
public:
    int id;
    long long next_free_time;

    Thread(int id){
        this->id = id;
        this->next_free_time = 0;
    }

    void addTime(long long time){
        this->next_free_time += time;
    }

};

struct Compare{
    bool operator()(Thread const &t1,Thread const &t2){
        if(t1.next_free_time == t2.next_free_time)
            return (t1.id > t2.id);
        else
            return t1.next_free_time > t2.next_free_time;
    }
};


class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    //vector<long long> next_free_time(num_workers_, 0);

    std::priority_queue<Thread, vector<Thread>, Compare> pq;

    for(int i = 0; i < num_workers_; i++)
        pq.push(Thread(i));

    for(int i = 0; i < jobs_.size(); i++){
        int duration = jobs_[i];
        Thread thread = pq.top();
        pq.pop();
        assigned_workers_[i] = thread.id;
        start_times_[i] = thread.next_free_time;
        thread.next_free_time += duration;
        pq.push(thread);
    }
/*    for (int i = 0; i < jobs_.size(); ++i) {
      int duration = jobs_[i];
      int next_worker = 0;
      for (int j = 0; j < num_workers_; ++j) {
        if (next_free_time[j] < next_free_time[next_worker])
          next_worker = j;
      }
      assigned_workers_[i] = next_worker;
      start_times_[i] = next_free_time[next_worker];
      next_free_time[next_worker] += duration;
    }*/
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
