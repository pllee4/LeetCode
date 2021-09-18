class H2O {
 public:
  H2O() { ResetCount(); }

  void hydrogen(function<void()> releaseHydrogen) {
    std::unique_lock<std::mutex> lock(mutex_);
    cond_var_.wait(lock, std::bind(&H2O::IsHydrogenNotEnough, this));
    // if hydrogen is not enough
    releaseHydrogen();
    hydrogen_count_++;

    if (GetHydrogenCount() == 2 && GetOxygenCount() == 1) {
      ResetCount();
    }
    cond_var_.notify_one();
  }

  void oxygen(function<void()> releaseOxygen) {
    std::unique_lock<std::mutex> lock(mutex_);
    cond_var_.wait(lock, std::bind(&H2O::IsOxygenNotEnough, this));
    // if oxygen is not enough
    releaseOxygen();
    oxygen_count_++;

    if (GetHydrogenCount() == 2 && GetOxygenCount() == 1) {
      ResetCount();
    }
    cond_var_.notify_all();
  }

 private:
  std::mutex mutex_;
  std::condition_variable cond_var_;
  int hydrogen_count_;
  int oxygen_count_;

  int GetHydrogenCount() { return hydrogen_count_; }

  int GetOxygenCount() { return oxygen_count_; }

  void ResetCount() {
    hydrogen_count_ = 0;
    oxygen_count_ = 0;
  }

  bool IsHydrogenNotEnough() { return GetHydrogenCount() < 2; }

  bool IsOxygenNotEnough() { return GetOxygenCount() < 1; }
};