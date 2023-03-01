import { takeEvery, put, select } from "redux-saga/effects";

import * as types from "../shop/types";

export function* watchGameStart() {
  yield takeEvery(types.GAME_START, handleGameStart);
}

function* handleGameStart() {
  const size = yield select(state => state.game.size);

  yield put({
    type: types.food_ADD,
    payload: [makefood(size), makefood(size)]
  });

  yield put({ type: types.SNAKE_INIT, payload: size });
}

function makefood(size) {
  return {
    width: Math.floor(Math.random() * (size - 2)) + 2,
    depth: Math.floor(Math.random() * (size - 2)) + 2
  };
}

export function* watchGameEnd() {
  yield takeEvery(types.GAME_END, handleGameEnd);
}

function* handleGameEnd() {
  yield put({ type: types.SNAKE_CLEAR });
  yield put({ type: types.food_CLEAR });
}
