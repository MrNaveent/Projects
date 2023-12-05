import { soap } from "strong-soap";

const wsdlUrl =
  process.env.WSDL_URL || "https://soap.contactlab.it/soap/services?wsdl";
const apiKey =
  process.env.API_KEY || "99999999836fb2c8a0fa3f05cb7f4c359058b289";
const userKey =
  process.env.USER_KEY || "0000000080d418f0cefcd0d8166dde66f224787e";
const sourceIdentifier = process.env.SOURCE_IDENTIFIER || 6;

const createSoapClient = () => {
  return new Promise((resolve, reject) => {
    soap.createClient(wsdlUrl, {}, (err, client) => {
      if (err) {
        reject(err);
      } else {
        resolve(client);
      }
    });
  });
};
// TO GET THE AUTH TOKEN
const getAuthToken = async () => {
  const client = await createSoapClient();

  const resp = await client.borrowToken({ apiKey, userKey });
  return resp.result.return.content;
};

const authToken = await getAuthToken();
console.log("get auth token", authToken);

if (!authToken) {
  throw new Error("Unable to get access token");
}

// TO GET THE DATA
const getData = async () => {
  const resp = await fetch("http://localhost:3000/user/1");
  if (resp.ok) {
    return await resp.json();
  } else {
    console.log(resp.status);
    console.log("error");
  }
};
const userData = await getData();
console.log(userData);

// TO ADD SUBSCRIBER DATA

const addSubscriber = async (userData, sourceIdentifier, token) => {
  const client = await createSoapClient();

  const subscriber = {
    attributes: [
      {
        key: "EMAIL",
        value: {
          $value: userData.EMAIL,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}string",
            "xsi:type": "ns2:string",
          },
        },
      },

      {
        key: "NOME",
        value: {
          $value: userData.NOME,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}string",
            "xsi:type": "ns2:string",
          },
        },
      },

      {
        key: "COGNOME",
        value: {
          $value: userData.COGNOME,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}string",
            "xsi:type": "ns2:string",
          },
        },
      },

      {
        key: "CELLULARE",
        value: {
          $value: userData.CELLULARE,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}string",
            "xsi:type": "ns2:string",
          },
        },
      },

      {
        key: "DT_LEAD",
        value: {
          $value: userData.DT_LEAD,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}date",
            "xsi:type": "ns2:date",
          },
        },
      },

      {
        key: "CONSENSO_PRIVACY",
        value: {
          $value: userData.CONSENSO_PRIVACY,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}string",
            "xsi:type": "ns2:string",
          },
        },
      },

      {
        key: "CONSENSO_MARKETING",
        value: {
          $value: userData.CONSENSO_MARKETING,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}string",
            "xsi:type": "ns2:string",
          },
        },
      },

      {
        key: "__cls1",
        value: {
          $value: userData.__cls1,
          $attributes: {
            $xsiType: "{http://www.w3.org/2001/XMLSchema}int",
            "xsi:type": "ns2:int",
          },
        },
      },
    ],
  };

  const payload = {
    token: { content: token },
    sourceIdentifier,
    subscriber,
  };

  try {
    const resp = await client.addSubscriber(payload, {});
    return resp.result.return.identifier;
  } catch (err) {
    console.log(err.response.request.body);
    console.log(err.root.Envelope.Body.Fault);
  }
};
const identifier = await addSubscriber(userData, sourceIdentifier, authToken);
console.log(identifier);

// TO POST THE IDENTIFIER IN THE DATABASE

const data = {
  identifier,
};
const customHeaders = {
  "Content-Type": "application/json",
};
const pushIdentifier = () => {
  fetch("http://localhost:3000/identifier_no", {
    method: "POST",
    headers: customHeaders,
    body: JSON.stringify(data),
  })
    .then((response) => response.json())
    .then((data) => {
      console.log(data);
    });
};

pushIdentifier();
