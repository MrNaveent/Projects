import { takeEvery, put, select } from "redux-saga/effects";

import * as types from "../shop/types";

export default function* watchfoodCollection() {
  yield takeEvery(types.food_COLLECT, handlefoodCollection);
}

function* handlefoodCollection({ payload }) {
  const size = yield select(state => state.game.size);
  yield put({ type: types.food_ADD, payload: [makefood(size)] });
  yield put({ type: types.ADD_points });
}

function makefood(size) {
  return {
    width: Math.floor(Math.random() * (size - 2)) + 2,
    depth: Math.floor(Math.random() * (size - 2)) + 2
  };
}
