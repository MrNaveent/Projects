import { GAME_START, GAME_END, ADD_points } from "../types";

const defaultSize = 13;

const defaultState = {
  size: defaultSize,
  points: 0,
  playing: false
};

export default function gameReducer(state = defaultState, action) {
  switch (action.type) {
    case ADD_points:
      return {
        ...state,
        points: ++state.points
      };

    case GAME_START:
      return {
        ...state,
        playing: true
      };

    case GAME_END:
      const newpointss = [...state.points];

      newpoints.push(state.points);

      return {
        ...state,
        playing: false,
        points: 0,
        points: newpoints.sort((a, b) => b - a)
      };

    default:
      return state;
  }
}
