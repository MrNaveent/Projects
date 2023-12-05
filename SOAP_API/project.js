import { soap } from "strong-soap";

const wsdlUrl = "https://soap.contactlab.it/soap/services?wsdl";
const sourceId = 6;

// TO GET AUTH-TOKEN USING SOAP

var AuthHeader = {
  apiKey: "99999999836fb2c8a0fa3f05cb7f4c359058b289",
  userKey: "0000000080d418f0cefcd0d8166dde66f224787e",
};

const getAuthToken = async () => {
  const createSoapClient = new Promise((resolve, reject) =>
    soap.createClient(wsdlUrl, AuthHeader, (err, client) =>
      err ? reject(err) : resolve(client)
    )
  );

  const soapClient = await createSoapClient;
  const data = await soapClient.borrowToken(AuthHeader);
  return data.result.return;
};

const token = await getAuthToken();
console.log(token);

// GET THE DATA FROM THE REST API
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

//TO ADD THE SUBSCRIBER USING SOAP

var subscriberData = {
  
  token: token,
  sourceIdentifier: 6,
  subscriber: {
    // identifier:[],
    attributes: [
      {key: "EMAIL",
        value: { $value: userData.EMAIL,$attributes: {$xsiType: "{http://www.w3.org/2001/XMLSchema}string","xsi:type": "ns2:string",},},},
    ],
  },
};

const addSubscriber = async () => {
  const createSoapClient = new Promise((resolve, reject) =>
    soap.createClient(wsdlUrl, {}, (err, client) =>
      err ? reject(err) : resolve(client)
    )
  );
  console.log(await createSoapClient);
  const soapClient = await createSoapClient;
  const data = await soapClient.addSubscriber(subscriberData);
  return data;
};

try {
  console.log(await addSubscriber());
} catch (error) {
  console.log(error.response.request.body);
}


// const options = {
//   method: 'POST',
//   body: `<soap:Envelope
//     xmlns:xs="http://www.w3.org/2001/XMLSchema"
//     xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
//     xmlns:soap="http://www.w3.org/2003/05/soap-envelope"
//     xmlns:ws="http://ws.api.contactlab.com/">
//     <soap:Header/>
//     <soap:Body>
//         <ws:addSubscriber>
//             <!--Optional:-->
//             <token>
//                 <!--Optional:-->
//                 <content>${token}</content>
//             </token>
//             <sourceIdentifier>6</sourceIdentifier>
//             <!--Optional:-->
//             <subscriber>
//                 <!--Optional:-->
// <!--                <identifier>?</identifier>-->
//                 <!--1 or more repetitions:-->
//                 <attributes>
//                     <key>EMAIL</key>
//                     <value xsi:type="xs:string">gnci@glauco.it</value>

//                 </attributes>

//             </subscriber>
//         </ws:addSubscriber>
//     </soap:Body>
// </soap:Envelope>`
// };

// fetch('https://soap.contactlab.it/soap/services', options)
//   .then(response => response.text())
//   .then(response => console.log(response))
//   .catch(err => console.error(err));


// TO UPDATE THE DATA USING REST API
// const updateData = () => {
//   fetch("http://localhost:3000/user/7", {
//     method: "PATCH",
//     headers: {
//       "Content-Type": "application/json",
//     },
//     body: JSON.stringify({ name: "gogo", email: "bsackjaskca" }),
//   }).then((response) => console.log(response.status));
// };
// updateData();

// var AuthHeader =
//   '<AuthHeader xmlns="http://ws.api.contactlab.com/"><apiKey>99999999836fb2c8a0fa3f05cb7f4c359058b289</apiKey><userKey>0000000080d418f0cefcd0d8166dde66f224787e</userKey></AuthHeader>';

// var AuthHeader = {
//   apiKey: "99999999836fb2c8a0fa3f05cb7f4c359058b289",
//   userKey: "0000000080d418f0cefcd0d8166dde66f224787e",
// };
