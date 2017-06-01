
template<typename T>
// if T() has prob to throw a exception, then noexcept(T()) return a false.
void func() noexcept( noexcept(T()) )
{
}