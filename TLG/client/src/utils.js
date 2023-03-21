import { RadioButtonUnchecked } from "@mui/icons-material";

const emailRegExp =
  /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;

export const isNotEmpty = (value) => {
  if (
    value.length > 0 &&
    value !== "" &&
    value !== null &&
    value !== undefined &&
    value !== RadioButtonUnchecked
  )
    return true;
  else return false;
};

export const messageHasLength = (mess) => {
  if (mess.length > 10) return true;
  else return false;
};

export const validateEmail = (mail) => {
  if (emailRegExp.test(mail.toLowerCase())) return true;
  else return false;
};
