import { all } from "redux-saga/effects";

import coordintes from "./coordintes";
import food from "./food";
import { watchGameStart, watchGameEnd } from "./movement";

export default function* rootSaga() {
  yield all([
    coordintes(),
    food(),
    watchGameStart(),
    watchGameEnd()
  ]);
}

