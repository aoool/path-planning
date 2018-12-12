//
// Created by aoool on 28.10.18.
//

#ifndef PATH_PLANNING_STATE_HPP
#define PATH_PLANNING_STATE_HPP

#include <iostream>
#include <typeinfo>
#include <sstream>
#include <vector>
#include <unordered_map>

enum class State {
  KeepLane,
  PrepareLaneChangeLeft,
  PrepareLaneChangeRight,
  LaneChangeLeft,
  LaneChangeRight,
};

class FSM {
public:
  static const std::vector<State>& GetPossibleNextStates(State state);

private:
  static std::unordered_map< State, const std::vector<State> >  transition_map_;
};

inline std::ostream& operator <<(std::ostream& ostream, const State state) {
  switch (state) {
    case State::KeepLane:
      ostream << "KL";
      break;
    case State::PrepareLaneChangeLeft:
      ostream << "PLCL";
      break;
    case State::PrepareLaneChangeRight:
      ostream << "PLCR";
      break;
    case State::LaneChangeLeft:
      ostream << "LCL";
      break;
    case State::LaneChangeRight:
      ostream << "LCR";
      break;
    default:
      std::cerr  << "operator<<() for " << typeid(state).name() <<  " must handle " << state << " case" << std::endl;
      std::exit(EXIT_FAILURE);
  }

  return ostream;
}


#endif //PATH_PLANNING_STATE_HPP