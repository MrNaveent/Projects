import { createStore, applyMiddleware } from "redux";

import reducers from "./reducers/main1"

export default function configureStore(sagas) {
  return createStore(reducers, applyMiddleware(sagas))
}