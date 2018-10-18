/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file h
 * @author Marco "Swampy" Millan
 * @date 2018/10/17 2018
 * @brief the std headers for the container used in the engine, USE USING_EASTL
 * for EA stl containers
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#ifndef  USING_EASTL
# include <array>
# include <vector>
# include <deque>
# include <forward_list>
# include <list>
# include <stack>
# include <queue>
# include <set>
# include <map>
#else
# include <EASTL/allocator.h>
# include <EASTL/array.h>
# include <EASTL/vector.h>
# include <EASTL/deque.h>
# include <EASTL/list.h>
# include <EASTL/stack.h>
# include <EASTL/queue.h>
# include <EASTL/priority_queue.h>
# include <EASTL/set.h>
# include <EASTL/map.h>
#endif


namespace nauEngineSDK {
#ifndef USING_EASTL
  template<typename T, typename A = std::allocator<T>()>
  using Array           = std::array<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Vector          = std::vector<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Deque           = std::deque<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Forward_list    = std::forward_list<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using List            = std::list<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Stack           = std::stack<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Queue           = std::queue<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Priority_queue  = std::priority_queue<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Set             = std::set<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using MultiSet        = std::multiset<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using Map             = std::map<T, A>;
  template<typename T, typename A = std::allocator<T>()>
  using MultiMap        = std::multimap<T, A>;
#else
  template<typename T, typename A = EASTLAllocatorType>
  using Array           = eastl::array<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Vector          = eastl::vector<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Deque           = eastl::deque<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Forward_list    = std::forward_list<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using List            = eastl::list<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Stack           = eastl::stack<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Queue           = eastl::queue<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Priority_queue  = eastl::priority_queue<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Set             = eastl::set<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using MultiSet        = eastl::multiset<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using Map             = eastl::map<T, A>;
  template<typename T, typename A = EASTLAllocatorType>
  using MultiMap        = eastl::multimap<T, A>;
#endif
}