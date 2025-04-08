#pragma once

template<
    typename T,
    typename CreationPolicy,
    typename LifetimePolicy,
    typename ThreadingPolicy
>
class SingletonHolder {
public:
    static T& Instance() {
        if (!pInstance_) {
            typename ThreadingPolicy::Lock guard;
            if (!pInstance_) {
                if (destroyed_) LifetimePolicy::OnDeadReference();
                pInstance_ = CreationPolicy::Create();
                LifetimePolicy::ScheduleDestruction(pInstance_, &DestroySingleton);
            }
        }
        return *pInstance_;
    }

private:
    static void DestroySingleton() {
        CreationPolicy::Destroy(pInstance_);
        pInstance_ = nullptr;
        destroyed_ = true;
    }

    static T* pInstance_;
    static bool destroyed_;
};

template<typename T, typename CP, typename LP, typename TP>
T* SingletonHolder<T, CP, LP, TP>::pInstance_ = nullptr;

template<typename T, typename CP, typename LP, typename TP>
bool SingletonHolder<T, CP, LP, TP>::destroyed_ = false;
